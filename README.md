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

## ⚙️ Gereksinimler | Requirements

- GCC (MinGW) veya uyumlu bir C derleyicisi
- (Opsiyonel) Code::Blocks IDE (proje dosyası `.cbp`)

---

## 💻 Kullanım | Usage

### Derleme | Compilation

#### Makefile ile (Varsa)

```bash
make
./main
