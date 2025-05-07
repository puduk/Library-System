# 📚✨ Library Management System

🛠️ A handmade C++ library ecosystem with file-based logic, no SQL, and full pointer control.

A fully-featured, file-based 📁 library + user ecosystem built entirely in **C++**.  
❌ No SQL. No database. Just pure logic, classes, and smart file manipulation with `.txt` files.  
Built with 💻, 💡 and a lot of 💪 in just **1 month** — completed in **1 single day**.

---

## 🔥 Core Features

### 👥 Account System
- 🧑‍💼 Create & login as **User** or **Library Owner**
- 🔐 Password-protected access
- 🚫 Duplicate check (no reused names, phones, or emails)
- 📦 Data saved in `user.txt` and `library.txt`

### 🏢 Library Owner Panel
- ➕ Add books (with ID, date, category, price, etc.)
- ❌ Delete books (safely archived)
- 💰 Update book prices
- 🗑️ View deleted books
- 📄 Each library stored in its own `.txt` (e.g. `mylibrary.txt`)

### 👤 User Panel
- 📚 Browse available libraries
- 💸 Buy books (removed from library file, saved in your `_bought.txt`)
- 📥 Rent books (added to your `_rent.txt`, not removed)
- 📜 View buy & rent history in detail

### 🧠 File-Based Storage (no DB!)
- 📄 Uses only `.txt` files to persist all data
- 🧮 Dynamically calculates book count based on file contents
- 🧹 Book entries use a clear separator: `/-/`

### ⭐ Exit Rating System
- 🙋‍♂️ Ask for feedback when quitting the app
- 📈 Users and libraries can rate the app (0–10)
- 💾 Ratings stored in `rate.txt`

---

## 💡 Notes

- ✅ Project contains **45+ files** including `.cpp` & `.hpp`
- 🔁 Data fully preserved between sessions using file I/O
- ⏱️ Created from scratch in **~12 hours** of focused coding
- 🎓 Final project for university — built with professional care

---

## 💻 Tech Stack

- 🚀 **C++** (OOP, Pointers, File Streams, Menus)
- 🧪 Compiled with g++ / CLion
- 📟 100% terminal interface
- 🔁 No third-party libraries

---

## 🧠 Advanced Concepts & Code Practices

- 🔗 All data is dynamically allocated on the **heap** using raw pointers  
- 🧠 Maximum usage of `new` / `delete` and deep manual memory management  
- 🚫 No use of helper tools like `struct`, `vector`, `array`, or `smart pointers`  
- 🧼 Code was repeatedly tested — **no discovered memory leaks**  
- 🛠 Designed with a deep focus on logic, control flow, and data isolation  
- 🧃 Pure, pointer-based simulation — zero shortcuts

---

## 🤝 AI Support (1%)

This project was hand-coded from scratch with ~99% manual effort.  
Around 1% of guidance, idea validation, and logic debugging was assisted by AI.

> No AI-generated code was directly copied — all logic was self-implemented.

---

## 🌱 Future Plans (Summer or Autumn 2025)

- 🖥️ A full **GUI version** of this system is planned using **Qt Framework**
- 🎨 All current logic will be preserved and upgraded with a modern interface
- 🔧 Project will be modularized and ported for better UI/UX experience
- 🧩 Potential multi-language support: **Polish 🇵🇱**, **Russian 🇷🇺**, **Turkish 🇹🇷**

---

## ⚙️ Compile & Run

```bash
g++ -std=c++17 main.cpp -o LibraryApp
./LibraryApp
```
## First Page

```
--------------------------------
1 :: for Sign in User Account
2 :: for Sign in Library Account
3 :: for Create User Account
4 :: for Create Library Account
5 :: for Exit
--------------------------------
```

## Create Library Account
```
Library Name : 
Aurora Central Library

Library Password : 
123123

Library Owner : 
Mert Demir

Library Address : 
1450 Harmony St, Aurora, CO, USA

Library Email : 
contact@auroralibrary.org

Library Phone : 
+1 (720) 555-0193

Add your first book data.
```

## Sign In Library Account And Delete Book Data
```
Name: 
Aurora Central Library

Password: 
123123

Welcome, Aurora Central Library!
Library system loaded. Book list:
1. Book Name : The Echoes of Solitude
1. Book Date : Lysandra
1. Book Category : Hale
1. Book Price : 23
1. Book Page : 23
1. Book Author : 23
/-/
2. Book Name : Whispers Between Worlds
2. Book Date : 2022-11-17
2. Book Category : Science Fiction
2. Book Price : 61.75
2. Book Page : 412
2. Book Author : Kael Dorian
/-/

1 :: for add book 
2 :: for delete book 
3 :: for update book price 
4 :: for showing deleted books
5 :: Quit
---------------------------
2
Current books.
1. Book Name : The Echoes of Solitude
2. Book Name : Whispers Between Worlds
----------------------------
Your Choice: 
2
Successfully deleted.

```
