# Elektrik Şirketi Otomasyon Sistemi | Electricity Company Automation System

## 📄 Açıklama | Description

Bu proje, elektrik şirketlerinin müşteri işlemlerini yönetmek amacıyla C dili kullanılarak geliştirilmiş bir **menü tabanlı otomasyon sistemidir**.  
Projede **struct yapıları** ve **pointer** kullanımıyla müşteri bilgileri ve işlemler dinamik olarak yönetilir. Kullanıcı dostu bir menü arayüzü üzerinden müşteri ekleme, silme, listeleme, fatura hesaplama ve ödeme işlemleri gerçekleştirilebilir.  

---

This project is a **menu-driven automation system** developed in C for managing customer operations in electricity companies.  
It uses **structs** and **pointers** to manage customer data dynamically. Through a user-friendly menu, users can add, delete, list customers, calculate invoices, and process payments.

---

## 🚀 Özellikler | Features

- Yeni müşteri kaydı ekleme
- Müşteri bilgilerini listeleme
- Müşteri bilgilerini güncelleme
- Müşteri kaydını silme
- Sayaç değeri güncelleme ve fatura hesaplama (tarifeye göre indirimli)
- Fatura ödeme
- Güvence bedeli ödeme işlemleri

---

- Add new customer record
- List customer information
- Update customer information
- Delete customer record
- Update meter value and calculate invoices (discount applied based on tariff)
- Invoice payment
- Security deposit payment operations

---

## 💬 Menü İşlemleri | Menu Operations

### TR

1️⃣ **Kayıt Listele** — Mevcut tüm müşteri kayıtlarını detaylı olarak listeler.  
2️⃣ **Fatura Hesaplama** — Sayaç değeri girilir, fark hesaplanır ve tarifeye göre indirim uygulanarak yeni fatura oluşturulur.  
3️⃣ **Yeni Müşteri Kayıt** — Yeni bir müşteri kaydı yapılır.  
4️⃣ **Fatura Ödeme** — Müşterinin borçlu olduğu faturayı ödemesine imkân tanır.  
5️⃣ **Kayıt Sil** — Müşteri kaydı silinir (blok boşaltma yöntemiyle).  
6️⃣ **Güvence Ödeme** — Güvence bedeli ödemesi yapılır.  
7️⃣ **Liste Güncelle** — Kayıt yılı, tarife, sayaç değeri veya fatura gibi bilgiler güncellenir.  
8️⃣ **Programı Kapat** — Program sonlandırılır.

---

### EN

1️⃣ **List Records** — Lists all customer records in detail.  
2️⃣ **Calculate Invoice** — Enter new meter value, calculate consumption difference, and generate invoice with tariff-based discount.  
3️⃣ **Add New Customer** — Register a new customer with details.  
4️⃣ **Pay Invoice** — Allows the customer to pay outstanding invoices.  
5️⃣ **Delete Record** — Deletes a customer record (block-clearing method).  
6️⃣ **Pay Security Deposit** — Allows payment of the security deposit.  
7️⃣ **Update Record** — Update details like registration year, tariff, meter value, or invoice.  
8️⃣ **Exit Program** — Closes the application.

---

## 💻 Kullanım | Usage

### Derleme | Compilation

```bash
gcc main.c -o main.exe
./main.exe
