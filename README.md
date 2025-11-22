# C++ Object Lifecycle Analysis

![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![Standard](https://img.shields.io/badge/std-C%2B%2B17%20%2F%2020-blue.svg)
![Status](https://img.shields.io/badge/status-Completed-green.svg)

## 📖 About The Project

This repository contains a comprehensive study of object lifecycles in C++. The main goal of this project is to analyze the behavior of different constructors, memory management techniques, and initialization patterns through a custom logging system.

The project demonstrates the implementation of the **Singleton** pattern and provides a deep dive into standard container optimizations (`push_back` vs `emplace_back`).

## 🛠 Features & Concepts Implemented

* **Custom Logger (Singleton Pattern):**
    * [cite_start]Implemented a thread-safe Logger class ensuring a single instance throughout the program execution[cite: 14, 45].
    * [cite_start]Supports multiple severity levels: `ERROR`, `WARNING`, `INFO`, `DEBUG`[cite: 47].
    * Used for tracing object creation and destruction orders.

* **Constructor & Destructor Analysis:**
    * [cite_start]**TrackedString Class:** A wrapper around `std::string` to log internal events[cite: 78].
    * [cite_start]Detailed tracking of **Default**, **Copy**, and **Move** constructors[cite: 83].
    * [cite_start]Implementation of **Delegating Constructors** to reduce code duplication[cite: 133].

* **Memory Optimization & Best Practices:**
    * [cite_start]**Initialization Lists:** Analysis of the "two objects problem" and how member initializer lists prevent unnecessary object creation[cite: 106].
    * [cite_start]**Standard Containers:** Comparative analysis of `std::vector::push_back` vs `std::vector::emplace_back` to demonstrate in-place construction and efficiency[cite: 146].

* **Operator Overloading:**
    * [cite_start]Custom implementation of stream insertion (`<<`), comparison (`==`, `!=`, `<`), and arithmetic operators for custom classes[cite: 159].

## 🚀 Getting Started

### Prerequisites

* C++ Compiler (GCC/Clang/MSVC) supporting C++17 or later.
* CMake (optional, if you use it for building).

### Compilation and Run

You can compile the project using `g++`:

```bash
# Compile all source files
g++ -std=c++17 main.cpp -o app

# Run the application
./app
