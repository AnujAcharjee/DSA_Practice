# Common Interview Questions in Java

## 1. What is Java?

Java is a **class-based, object-oriented, general-purpose programming language** designed with simplicity, security, and platform independence in mind.

### Key Feature: Write Once, Run Anywhere (WORA)

- Java source code (`.java`) is compiled into **bytecode** (`.class`) by the Java compiler (`javac`).
- This bytecode can run on any platform that has a compatible Java Virtual Machine (JVM).

## Why is Java NOT a Pure Object-Oriented Programming Language?

Java is considered object-oriented, but it is not a *pure* object-oriented programming language because it does not enforce everything to be an object.

There are two major reasons:

### 1. Primitive Data Types

Java provides 8 primitive data types that are not objects.

| Primitive | Purpose |
|---|---|
| `byte` | Small integer |
| `short` | Short integer |
| `int` | Integer |
| `long` | Large integer |
| `float` | Decimal number |
| `double` | Double-precision decimal |
| `char` | Single character |
| `boolean` | True or false |

Java provides wrapper classes such as `Integer`, `Character`, and `Boolean` to represent primitive values as objects.

### 2. Static Members

Java supports `static` variables and methods that belong to the class rather than individual objects.

They can be accessed without creating an instance of the class.

## 2. Explain the key components involved in running a Java program?

```
+-------------------------------------------------------+
| JDK (Java Development Kit)                            |
|  +-------------------------------------------------+  |
|  | JRE (Java Runtime Environment)                  |  |
|  |  +---------------------+  +------------------+  |  |
|  |  | JVM                 |  | Core Libraries   |  |  |
|  |  | (Executes Bytecode) |  | (rt.jar, APIs)   |  |  |
|  |  +---------------------+  +------------------+  |  |
|  +-------------------------------------------------+  |
|  Development Tools (javac, jdb, javap, jar, etc.)     |
+-------------------------------------------------------+
```

- **JVM (Java Virtual Machine)**: Platform-dependent runtime engine that converts bytecode (`.class`) into machine code via interpreter + JIT (Just-In-Time) compiler. Manages memory (Garbage Collector).
- **JRE (Java Runtime Environment)**: JVM + standard runtime class libraries. Minimum requirement to **run** Java programs.
- **JDK (Java Development Kit)**: JRE + developer tools (compiler `javac`, debugger, packagers). Required to **develop and compile** Java programs.

