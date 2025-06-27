/*
Author: Enes Elmas
Date: 2022-12-28

Açıklama (TR):
Bu proje, C diliyle geliştirilen, elektrik şirketlerinin müşteri işlemlerini yönetmek amacıyla oluşturulmuş menü tabanlı bir otomasyon sistemidir.
Projede struct yapıları ve pointer kullanılarak dinamik bellek yönetimi yapılmaktadır.

Description (EN):
This project is a menu-driven automation system written in C for managing customer operations in electricity companies.
It uses structs and pointers for efficient data handling and dynamic memory management.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musteri_bilgi
{
    char isim[10];
    char soyisim[10];
    int yas;
    char memleket[20];

} musteri;

typedef struct genel_bilgi
{
    int musteri_id;
    int kayit_yili;
    int guvence_bedeli;
    int tarife;
    int sayac_degeri;
    int odenmemis_fatura;
    struct musteri_bilgi a;     //****struct icinde struct yapisi kullanildi.****

} Genel;
Genel *gb;   //gb=genel bilgi.


//************************************************************************************************************************************************************

void kayit_listele(int *ms)
{

    system("cls");
    if(*ms==0)
    {
        printf("Kayitli musteri mevcut degil..\n");         //musteri yok ise fonksiyon calismayacak ve ana menuye donecek.
        return;
    }
    int i,j;
    printf("\t\t  Id\t  Kayit Yili\t  Guvence Bedeli    Tarife\t  Sayac Degeri\t Odenmemis Fatura\n");
    printf("----------------|-------|---------------|---------------|---------------|---------------|---------------|\n");

    for(i=0 ; i<*ms ; i++)
    {
        printf("%s %s[%d]",(gb +i)->a.isim,(gb +i)->a.soyisim,(gb +i)->a.yas);
        printf("\t| %d   |",(gb + i)->musteri_id);
        printf("     %d\t|",(gb + i)->kayit_yili);
        printf("   %d TL\t|",(gb + i)->guvence_bedeli);
        printf("\t%d\t|",(gb + i)->tarife);
        printf(" %d\t\t|",(gb + i)->sayac_degeri);
        printf("\t%d TL\t|",(gb + i)->odenmemis_fatura);
        printf("\n");
        printf("----------------|-------|---------------|---------------|---------------|---------------|---------------|\n");
    }

    if(*ms==0)
        printf("\nMusteri Kayidi Bulunamadi...\n");

}

//************************************************************************************************************************************************************

int yeni_fatura(int *ms)
{
    system("cls");
    int girilen,i,fark,fatura,ind_fatura;
    int yenisayac;
    if(*ms==0)
    {
        printf("Kayitli musteri mevcut degil..\n");
        return;
    }
    printf("Fatura Hesaplama Ekrani\n-------------------\n");
    printf("Musteri Id Giriniz :");                             //girilecek müsteri id ne göre fatura odenecek
    scanf("%d",&girilen);
    while(girilen>99+*ms || girilen<100)
    {
        printf("Girdiginiz musteri Id bulunamadi , Musteri Id giriniz :");      //girilen musteri id bulunamazsa tekrar soracak.
        scanf("%d",&girilen);
    }

    for(i=0 ; i<*ms ; i++)
    {
        if((gb + i)->musteri_id == girilen)
        {
            printf("\nMevcut sayac degeri :%d\n",(gb + i)->sayac_degeri);       //girilen musteri id nin mevcut sayac degeri ekrana yazdirildi.
            printf("\nYeni sayac degeri   :");                                  //yeni sayac degeri soruldu.
            scanf("%d",&yenisayac);
            while(yenisayac<=(gb +i)->sayac_degeri)
            {
                printf("Mevcut sayac degerinden kucuk(esit) deger giremezsiniz...\n");          //mevcut sayactan kucuk ise hata verecek.
                printf("\nYeni sayac degeri   :");
                scanf("%d",&yenisayac);
            }

            fark = yenisayac - (gb +i)->sayac_degeri ;
            fatura=fark*0.6;                                            //fatura hesaplandi.
            printf("\nIndirimsiz fatura :%d\n",fatura);
            (gb +i)->sayac_degeri=yenisayac;

            if((gb +i)->tarife == 1)
            {
                printf("\nTarife '1' %%10 indirim uygulandi...\n");         //burdaki tarifelere göre faturaya indirim uygulandi.
                ind_fatura=fatura*0.9;
                printf("Indirimli fatura :%d\n",ind_fatura);
                (gb +i)->odenmemis_fatura=ind_fatura;
            }
            else if((gb +i)->tarife == 2)
            {
                printf("\nTarife '2' %%12 indirim uygulandi...\n");
                ind_fatura=fatura*0.88;
                printf("Indirimli fatura :%d\n",ind_fatura);
                (gb +i)->odenmemis_fatura=ind_fatura;
            }
            else if((gb +i)->tarife == 3)
            {
                printf("\nTarife '3' %%15 indirim uygulandi...\n");
                ind_fatura=fatura*0.85;
                printf("Indirimli fatura :%d\n",ind_fatura);
                (gb +i)->odenmemis_fatura=ind_fatura;
            }
            else
            {
                printf("\nTarife '4' %%18 indirim uygulandi...\n");
                ind_fatura=fatura*0.82;
                printf("Indirimli fatura :%d\n",ind_fatura);
                (gb +i)->odenmemis_fatura=ind_fatura;
            }
        }
    }
    printf("\nFatura ve Sayac degerleri guncellendi...\n");
}


//************************************************************************************************************************************************************


void yeni_musteri(int *ms)
{
    char ad[20];        //strcpy ile pointere kopyalamak icin kullanilacak.
    char soyad[20];     //strcpy ile pointere kopyalamak icin kullanilacak.
    char sehir[20];     //strcpy ile pointere kopyalamak icin kullanilacak.

    if (*ms == 0)
    {
        gb = (Gene l *) malloc(sizeof(Genel));                                       //*****genel bilgileri tutmak ici dinamik bellek ile yer ayrildi.******
    }
    else
    {
        gb = (Genel *) realloc(gb, sizeof(Genel) * (*ms + 1));                      //*****musteri sayisi artinca realloc ile bellek arttirildi.******
    }
    system("cls");

    for(int i=0 ; i<*ms ; i++)
    {
        if((gb + i)->kayit_yili == 1000)                        //silinmis bir blok varsa oraya kayit yaptirir bu kisim.
        {
            printf("Musteri Bilgileri :\n----------------\n");
            printf("ad       :");
            scanf("%s",&ad);
            strcpy((gb + i)->a.isim, ad);                           //girilen isim , isim structina kopyalandi.
            printf("soyad    :");
            scanf("%s",&soyad);
            strcpy((gb + i)->a.soyisim,soyad);                      //girilen soyisim , soyisim structina kopyalandi.
            printf("yas      :");
            scanf("%d",&(gb + i)->a.yas);
            printf("memleket :");
            scanf("%s",&sehir);
            strcpy((gb + i)->a.memleket,sehir);                     //girilen sehir , memleket structina kopyalandi.

            printf("Kayit bilgileri : \n-------------\n");

            printf("4 Haneli kayit yili giriniz :");
            scanf("%d",&(gb+i)->kayit_yili);
            printf("\nTarife 1 : Guvence bedeli 400TL , Faturaya %%10 indirim.\nTarife 2 : Guvence bedeli 450TL , Faturaya %%12  indirim.\nTarife 3 : Guvence bedeli 500TL , Faturaya %%15  indirim.\nTarife 4 : Guvence bedeli 550TL , Faturaya %%18  indirim.\n");
            int secilen;
            printf("Tarife seciniz :");
            scanf("%d",&secilen);
            while(secilen!=1 && secilen!=2 && secilen!=3 && secilen!=4)
            {
                printf("Hatali tuslama lutfen tekrar tarife seciniz :");
                scanf("%d",&secilen);
            }
            if(secilen==1)
            {
                (gb + i)->guvence_bedeli=400;
                printf("\nTarifeniz '1' olarak belirlendi\n");                      //secilen tarifeye gore guvence bedellerine degerler atandi.
                printf("\nGuvence bedeli 400TL olarak belirlendi.\n");
            }
            else if(secilen==2)
            {
                (gb + i)->guvence_bedeli=450;
                printf("\nTarifeniz '2' olarak belirlendi\n");
                printf("\nGuvence bedeli 450TL olarak belirlendi.\n");
            }
            else if(secilen==3)
            {
                (gb + i)->guvence_bedeli=500;
                printf("\nTarifeniz '3' olarak belirlendi\n");
                printf("\nGuvence bedeli 500TL olarak belirlendi.\n");
            }
            else
            {
                (gb + i)->guvence_bedeli=550;
                printf("\nTarifeniz '4' olarak belirlendi\n");
                printf("\nGuvence bedeli 550TL olarak belirlendi.\n");
            }

            (gb + i)->tarife=secilen;

            printf("\n(1-5)Haneli mevcut sayac degerini giriniz :");
            scanf("%d",&(gb+i)->sayac_degeri);

            (gb + i)->odenmemis_fatura=0;

            return;
        }
    }


    printf("Musteri bilgileri : \n-------------\n");            //herhangi bir bosluk yoksa , yeni blok acarak kayit yapan kisim.

    (gb + *ms)->musteri_id=100+*ms;
    printf("ad       :");
    scanf("%s",&ad);
    strcpy((gb + *ms)->a.isim, ad);
    printf("soyad    :");
    scanf("%s",&soyad);
    strcpy((gb + *ms)->a.soyisim,soyad);
    printf("yas      :");
    scanf("%d",&(gb + *ms)->a.yas);
    printf("memleket :");
    scanf("%s",&sehir);
    strcpy((gb + *ms)->a.memleket,sehir);

    printf("Kayit bilgileri : \n-------------\n");


    printf("4 Haneli kayit yili giriniz :");
    scanf("%d",&(gb+*ms)->kayit_yili);
    printf("\nTarife 1 : Guvence bedeli 400TL , Faturaya %%10 indirim.\nTarife 2 : Guvence bedeli 450TL , Faturaya %%12  indirim.\nTarife 3 : Guvence bedeli 500TL , Faturaya %%15  indirim.\nTarife 4 : Guvence bedeli 550TL , Faturaya %%18  indirim.\n");
    int secilen;
    printf("Tarife seciniz :");
    scanf("%d",&secilen);
    while(secilen!=1 && secilen!=2 && secilen!=3 && secilen!=4)
    {
        printf("Hatali tuslama lutfen tekrar tarife seciniz :");
        scanf("%d",&secilen);
    }
    if(secilen==1)
    {
        (gb + *ms)->guvence_bedeli=400;
        printf("\nTarifeniz '1' olarak belirlendi\n");
        printf("\nGuvence bedeli 400TL olarak belirlendi.\n");
    }
    else if(secilen==2)
    {
        (gb + *ms)->guvence_bedeli=450;
        printf("\nTarifeniz '2' olarak belirlendi\n");
        printf("\nGuvence bedeli 450TL olarak belirlendi.\n");
    }
    else if(secilen==3)
    {
        (gb + *ms)->guvence_bedeli=500;
        printf("\nTarifeniz '3' olarak belirlendi\n");
        printf("\nGuvence bedeli 500TL olarak belirlendi.\n");
    }
    else
    {
        (gb + *ms)->guvence_bedeli=550;
        printf("\nTarifeniz '4' olarak belirlendi\n");
        printf("\nGuvence bedeli 550TL olarak belirlendi.\n");
    }

    (gb + *ms)->tarife=secilen;

    printf("\n(1-5)Haneli mevcut sayac degerini giriniz :");
    scanf("%d",&(gb+*ms)->sayac_degeri);

    (gb + *ms)->odenmemis_fatura=0;

    *ms=*ms+1;      //musteri sayisi arttirildi.

}


//************************************************************************************************************************************************************


int fatura_ode(int *ms)
{
    system("cls");
    if(*ms==0)
    {
        printf("Kayitli musteri mevcut degil..\n");
        return;
    }
    int girilen,i,miktar;
    printf("Fatura Odeme Ekrani\n----------------\n");
    printf("Musteri ID:");
    scanf("%d",&girilen);
    while(girilen>99+*ms || girilen<100)
    {
        printf("Girdiginiz musteri Id bulunamadi , Musteri Id giriniz :");
        scanf("%d",&girilen);
    }

    for(i=0 ; i<*ms ; i++)
    {
        if((gb + i)->musteri_id == girilen)
        {
            if((gb +i)->odenmemis_fatura ==0)
            {
                printf("Odenmemis faturaniz bulunmamaktadir...\n");
                return;
            }
            printf("Odenmemis Fatura :%d\n",(gb +i)->odenmemis_fatura);
            printf("Odeyeceginiz Miktar :");                            //odenmemis fatura ekrana yansitildi ve odeyecegi miktar soruldu.
            scanf("%d",&miktar);
            while(miktar>(gb +i)->odenmemis_fatura)
            {
                printf("\nOdenmemis faturanizdan yuksek deger girdiniz.Tekrar giriniz.\n ");        //yuksek deger girerse tekrar sordu.
                printf("\nOdeyeceginiz Miktar :");
                scanf("%d",&miktar);
            }

            (gb +i)->odenmemis_fatura = (gb +i)->odenmemis_fatura - miktar;                 //odenmemis faturadan , odeyecegi miktar cikartildi ve guncellendi.
            printf("Fatura Basariyla Odendi Kalan Fatura :%d\n",(gb +i)->odenmemis_fatura);
        }
    }
}


//************************************************************************************************************************************************************


void kayit_sil(int *ms)
{
    int i,girilen,tuslanan;
    system("cls");
    printf("Kayit Silme Ekrani\n---------------------------------\n");
    printf("Silmek Istediginiz Musteri ID :");
    scanf("%d",&girilen);
    while(girilen>99+*ms || girilen<100)
    {
        printf("Girdiginiz musteri Id bulunamadi , Musteri Id giriniz :");
        scanf("%d",&girilen);
    }
    for(i=0 ; i<*ms ; i++)
    {
        if((gb + i)->musteri_id == girilen)
        {
            strcpy((gb+i)->a.isim, "xxxx");            //tablo kaymasin diye böyle atama yapildi silinen musteri yerine.
            strcpy((gb+i)->a.soyisim, "xxxx");
            (gb+i)->a.yas='\0';
            (gb+i)->kayit_yili=1000;            //tablo kaydigi icin bu deger 1000 yapildi.
            (gb+i)->guvence_bedeli='\0';
            (gb+i)->tarife='\0';
            (gb+i)->sayac_degeri='\0';
            (gb+i)->odenmemis_fatura='\0';
            printf("\n...%d Id'li Musteri Silindi...\n",girilen);
            printf("\n1-)Ana Menu\n2-)Programi Kapat\n");
            printf("Tuslama Yapiniz :");
            int tuslanan;
            scanf("%d",&tuslanan);
            while(tuslanan!=1 && tuslanan!=2)
            {
                printf("\nHatali Tuslama Tekrar Tuslama Yapiniz :");
                scanf("%d",&tuslanan);
            }
            if(tuslanan==1)
            {
                system("cls");
                return;
            }
            else
            {
                printf("\n\n...Program Kapatildi...\n\n");
                exit(1);
            }
        }

    }
}


//************************************************************************************************************************************************************


void guvence_ode(int *ms)
{
    system("cls");
    if(*ms==0)
    {
        printf("Kayitli musteri mevcut degil..\n");
        return;
    }
    int girilen,i,tuslanan;
    printf("Guvence Bedeli Odeme Ekrani\n---------------------------------\n");
    printf("Musteri ID :");
    scanf("%d",&girilen);
    while(girilen>99+*ms || girilen<100)
    {
        printf("Girdiginiz musteri Id bulunamadi , Musteri Id giriniz :");
        scanf("%d",&girilen);
    }

    for(i=0 ; i<*ms ; i++)
    {
        if((gb + *ms)->guvence_bedeli == girilen);
        {
            if((gb + i)->guvence_bedeli == 0)
            {
                printf("Odenmemis guvence bedeliniz bulunmamaktadir...\n");
                return;
            }
            printf("Guvence Bedeli :%d",(gb + i)->guvence_bedeli);
            printf("\n1-)Ode\n2-)Ana menu");
            printf("\nTuslama Yapiniz :");
            scanf("%d",&tuslanan);
            while(tuslanan!=1 && tuslanan!=2)
            {
                printf("Hatali Tuslama Tekrar Tuslayiniz :");
                scanf("%d",&tuslanan);
            }
            if(tuslanan==1)
            {
                (gb+i)->guvence_bedeli=0;
                printf("Guvence Bedeli Basariyla Odendi...");
                return;

            }
            else
                return;
        }
    }

}


//************************************************************************************************************************************************************


void liste_guncelle(int *ms)
{
    system("cls");
    int girilen,tuslanan,i;
    if(*ms==0)
    {
        printf("Kayitli musteri mevcut degil..\n");
        return;
    }
    printf("Liste Guncelleme Ekrani\n-----------------------\n");
    printf("Guncellemek Istediginiz Musteri ID :");
    scanf("%d",&girilen);
    while(girilen>99+*ms || girilen<100)
    {
        printf("Girdiginiz musteri Id bulunamadi , Musteri Id giriniz :");
        scanf("%d",&girilen);
    }

    for(i=0 ; i<*ms ; i++)
    {
        if((gb + i)->musteri_id == girilen)
        {
bilgi:
            printf("%d ID'li Musterinin Bilgileri :\n");
            printf("1-)Kayit Yili\n2-)Guvence Bedeli\n3-)Tarife\n4-)Sayac Degeri\n5-)Fatura\n6-)Ana Menu\n");
            printf("Guncellemek Istediginiz Bilgiyi Tuslayiniz :");
            scanf("%d",&tuslanan);
            while(tuslanan!=1 && tuslanan!=2 && tuslanan!=3 && tuslanan!=4 && tuslanan!=5 && tuslanan!=6)
            {
                printf("Hatali Tuslama...\n");
                printf("Guncellemek Istediginiz Bilgiyi Tuslayiniz :");
                scanf("%d",&tuslanan);
            }
            if(tuslanan==1)
            {
                printf("Mevcut Kayit Yili       :%d",(gb +i)->kayit_yili);
                printf("\nYeni Kayit Yili Girin :");
                scanf("%d",&(gb +i)->kayit_yili);
                printf("Kayit Yili Basariyla Guncellendi...\n\n");
                printf("1-)Ana Menu\n2-)Geri\n3-)Programi Kapat\n");
                printf("Tuslama Yapiniz :");
                int tuslanan1;
                scanf("%d",&tuslanan1);
                while(tuslanan1!=1 && tuslanan1!=2 && tuslanan1!=3)
                {
                    printf("\nHatali Tuslama Tekrar Tuslama Yapiniz :");
                    int tuslanan1;
                    scanf("%d",&tuslanan1);
                }
                if(tuslanan1==1)
                {
                    system("cls");
                    return;
                }
                else if(tuslanan1==2)
                {
                    system("cls");
                    goto bilgi;
                }
                else
                {
                    printf("\n\n...Program Kapatildi...\n\n");
                    exit(1);
                }


            }
            else if(tuslanan==2)
            {
                printf("Mevcut Guvence Bedeli       :%d",(gb +i)->guvence_bedeli);
                printf("\nYeni Guvence Bedeli Girin :");
                scanf("%d",&(gb +i)->guvence_bedeli);
                printf("Guvence Bedeli Basariyla Guncellendi...\n");
                printf("1-)Ana Menu\n2-)Geri\n3-)Programi Kapat\n");
                printf("Tuslama Yapiniz :");
                int tuslanan1;
                scanf("%d",&tuslanan1);
                while(tuslanan1!=1 && tuslanan1!=2 && tuslanan1!=3)
                {
                    printf("\nHatali Tuslama Tekrar Tuslama Yapiniz :");
                    int tuslanan1;
                    scanf("%d",&tuslanan1);
                }
                if(tuslanan1==1)
                {
                    system("cls");
                    return;
                }
                else if(tuslanan1==2)
                {
                    system("cls");
                    goto bilgi;
                }
                else
                {
                    printf("\n\n...Program Kapatildi...\n\n");
                    exit(1);
                }
            }
            else if(tuslanan==3)
            {
                printf("Mevcut Tarife : %d",(gb + i)->tarife);
                printf("\nTarife 1 : Guvence bedeli 400TL , Faturaya %%10 indirim.\nTarife 2 : Guvence bedeli 450TL , Faturaya %%12  indirim.\nTarife 3 : Guvence bedeli 500TL , Faturaya %%15  indirim.\nTarife 4 : Guvence bedeli 550TL , Faturaya %%18  indirim.\n");
                printf("Yeni Tarife Seciniz :");
                scanf("%d",&(gb +i)->tarife);
                printf("Tarife Basariyle Guncellendi...\n");
                printf("1-)Ana Menu\n2-)Geri\n3-)Programi Kapat\n");
                printf("Tuslama Yapiniz :");
                int tuslanan1;
                scanf("%d",&tuslanan1);
                while(tuslanan1!=1 && tuslanan1!=2 && tuslanan1!=3)
                {
                    printf("\nHatali Tuslama Tekrar Tuslama Yapiniz :");
                    int tuslanan1;
                    scanf("%d",&tuslanan1);
                }
                if(tuslanan1==1)
                {
                    system("cls");
                    return;
                }
                else if(tuslanan1==2)
                {
                    system("cls");
                    goto bilgi;
                }
                else
                {
                    printf("\n\n...Program Kapatildi...\n\n");
                    exit(1);
                }
            }
            else if(tuslanan==4)
            {
                printf("Mevcut Sayac Degeri    :%d",(gb + i)->sayac_degeri);
                printf("\nSayac Degeri Giriniz :");
                scanf("%d",&(gb+i)->sayac_degeri);
                printf("Sayac Degeri Basariyla Guncellendi...\n");
                printf("1-)Ana Menu\n2-)Geri\n3-)Programi Kapat\n");
                printf("Tuslama Yapiniz :");
                int tuslanan1;
                scanf("%d",&tuslanan1);
                while(tuslanan1!=1 && tuslanan1!=2 && tuslanan1!=3)
                {
                    printf("\nHatali Tuslama Tekrar Tuslama Yapiniz :");
                    int tuslanan1;
                    scanf("%d",&tuslanan1);
                }
                if(tuslanan1==1)
                {
                    system("cls");
                    return;
                }
                else if(tuslanan1==2)
                {
                    system("cls");
                    goto bilgi;
                }
                else
                {
                    printf("\n\n...Program Kapatildi...\n\n");
                    exit(1);
                }
            }
            else if(tuslanan==5)
            {
                printf("Mevcut Fatura    : %d",(gb +i)->odenmemis_fatura);
                printf("\nFatura Giriniz :");
                scanf("%d",&(gb +i)->odenmemis_fatura);
                printf("Fatura Basariyla Guncellendi...\n");
                printf("1-)Ana Menu\n2-)Geri\n3-)Programi Kapat\n");
                printf("Tuslama Yapiniz :");
                int tuslanan1;
                scanf("%d",&tuslanan1);
                while(tuslanan1!=1 && tuslanan1!=2 && tuslanan1!=3)
                {
                    printf("\nHatali Tuslama Tekrar Tuslama Yapiniz :");
                    int tuslanan1;
                    scanf("%d",&tuslanan1);
                }
                if(tuslanan1==1)
                {
                    system("cls");
                    return;
                }
                else if(tuslanan1==2)
                {
                    system("cls");
                    goto bilgi;
                }
                else
                {
                    printf("\n\n...Program Kapatildi...\n\n");
                    exit(1);
                }
            }
            else
                return;
        }
    }
}


//************************************************************************************************************************************************************



void ana_menu(int *ms)
{
    int tuslanan;
    printf("  Elektrik Sirket Otomosyonu\n-----------------------------\n");

    while(tuslanan!=8)
    {
        printf("\n***************************\n*  1-)Kayit Listele\t  *\n*  2-)Fatura Hesaplama    *\n*  3-)Yeni Musteri Kayit  *\n*  4-)Fatura Odeme        *\n*  5-)Kayit Sil\t\t  *\n*  6-)Guvence ODE\t  *\n*  7-)Liste Guncelle\t  *\n*  8-)Programi Kapat\t  *\n***************************\nTuslama Yapiniz:");
        scanf("%d",&tuslanan);
        while(tuslanan!=1 && tuslanan!=2 && tuslanan!=3 && tuslanan!=4 && tuslanan!=5 && tuslanan!=6 && tuslanan!=7 && tuslanan!=8)
        {
            printf("Hatali Tuslama Tekrar Tuslayiniz :");
            scanf("%d",&tuslanan);
        }
        switch(tuslanan)
        {
        case 1:
        {
            kayit_listele(ms);
            break;
        }
        case 2:
        {
            yeni_fatura(ms);
            break;
        }
        case 3:
        {
            yeni_musteri(ms);
            break;
        }
        case 4:
        {
            fatura_ode(ms);
            break;

        }
        case 5:
        {
            kayit_sil(ms);
            break;
        }
        case 6:
        {
            guvence_ode(ms);
            break;
        }
        case 7:
        {
            liste_guncelle(ms);
            break;
        }
        case 8:
        {
            printf("...PROGRAM KAPATILIYOR...");
            exit(0);
        }
        }
    }
}

//************************************************************************************************************************************************************


int main()
{
    int musteri_sayisi=0;
    int *ms;
    ms=&musteri_sayisi;
    ana_menu(ms);
}
