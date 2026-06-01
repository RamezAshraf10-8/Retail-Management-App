👗 Dress Rental Management System

A console-based C++ application for managing a dress rental store. Built using custom implementations of core data structures — no STL containers used.

---

## 📌 Features

### 👤 Customer Operations
- Add new customers to the database
- Remove existing customers
- Update customer information
- Display all customers
- Search and display a specific customer's info

### 👗 Dress Operations
- Add new dress types to the store's stock
- Remove dresses from stock
- Update dress information (price, size, stock)
- Display all available dresses

### 🧾 Rental Operations
- Rent a dress to a customer (max 5 dresses per customer)
- Return a rented dress (automatically updates stock)
- View all rentals for a specific customer
- Calculate a customer's total bill
- Calculate the store's total profit for the day

---

## 🗂️ Project Structure

```
├── header.h       # Class definitions for all data structures
└── main.cpp       # Full implementation + program logic
```

---

## 🧱 Data Structures Used

| Structure | Used For |
|---|---|
| Linked List | Storing customer records |
| Array List | Storing dresses and rental records |

Both data structures are built from scratch using templates, including full support for insert, delete, search, and copy operations.

---

## ▶️ How to Run

### Option 1 — VS Code
1. Clone the repo
2. Open the folder in VS Code
3. Make sure you have the **C/C++ extension** and **MinGW** installed
4. Press `F5` and select **C++ (Windows)**

### Option 2 — Dev-C++
1. Clone the repo
2. Open Dev-C++ and create a new project
3. Add both `main.cpp` and `header.h`
4. Press `F11` to compile and run

### Option 3 — Terminal
```bash
g++ -std=c++17 -o dress_rental main.cpp
./dress_rental
```

---

## 💡 Usage Notes

- **Customer IDs** and **Dress IDs** are integers (e.g. 1, 2, 3)
- A customer can rent a **maximum of 5 dresses** at a time
- Returning a dress automatically **restores it to stock**
- Dress sizes are entered as text: `small`, `medium`, or `large`

---

## 🛠️ Built With

- **Language:** C++
- **Paradigm:** Object-Oriented Programming
- **Data Structures:** Custom Linked List, Custom Array List (template-based)
<img width="1101" height="866" alt="image" src="https://github.com/user-attachments/assets/79b6ee7e-f366-4a8a-9d1c-61ab95950cb5" />
