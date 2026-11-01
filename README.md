# Programming Labs

University coursework, laboratory assignments and programming practice in **C++**.

Maintained by **Oleksandr Kosynskyi**, an Applied Mathematics student at **Oles Honchar Dnipro National University**. This repository records my progress from basic console exercises to data structures, text processing, matrix operations and SIMD experiments.

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![Visual Studio](https://img.shields.io/badge/Visual_Studio-5C2D91?style=flat-square)
![Windows](https://img.shields.io/badge/Platform-Windows-0078D4?style=flat-square)

## Topics covered

- Control flow, loops, functions and console input/output
- Arrays, sorting, searching and sequence processing
- Stack implementation and postfix expression evaluation
- Pointers, dynamic memory and two-dimensional arrays
- C-style strings, text files and command-line arguments
- Numerical calculations, matrix operations and execution-time measurements
- Scalar, SSE and AVX/AVX2 programming experiments

## Laboratory catalogue

Links in the last column point to the Visual Studio solution to open after cloning the repository.

| Assignment | What it covers | Open solution |
| --- | --- | --- |
| [Lab 01 — Arrays](cpp/lab-01-arrays/) | Menu-driven array generation, sums, element insertion and capacity checks | [Lab1_variant4.sln](cpp/lab-01-arrays/Lab1_variant4.sln) |
| [Lab 02 — Stack](cpp/lab-02-stack/) | Fixed-capacity stack, push/pop operations and postfix arithmetic with error handling | [Lab2_variant4.sln](cpp/lab-02-stack/Lab2_variant4.sln) |
| [Lab 03 — Conditions](cpp/lab-03/) | Conditional statements, comparisons and related introductory exercises | [Lab3.sln](cpp/lab-03/Lab3.sln) |
| [Lab 04 — Loops](cpp/lab-04/) | Sums, products, counting, Fibonacci numbers and factor-related exercises | [Lab4.sln](cpp/lab-04/Lab4.sln) |
| [Lab 05 — Divisibility](cpp/lab-05/) | Integer arithmetic and divisibility conditions involving squares and cubes | [Lab5.sln](cpp/lab-05/Lab5.sln) |
| [Lab 06 — Functions and series](cpp/lab-06/) | Piecewise function tabulation, numeric input parsing and series summation | [Lab6.sln](cpp/lab-06/Lab6.sln) |
| [Lab 07 — Array processing](cpp/lab-07/) | Even/odd partitioning, sorting, minimum search and sequence-order checks | [lab7.sln](cpp/lab-07/lab7.sln) |
| [Lab 08 — Dynamic matrices](cpp/lab-08/) | Dynamic allocation, console/file input, extrema, diagonal processing and row sorting | [Lab8.sln](cpp/lab-08/Lab8.sln) |
| [Lab 09 — Strings and files](cpp/lab-09/) | Word manipulation, custom string functions and file-processing exercises | [Lab9.sln](cpp/lab-09/Lab9.sln) |

### Matrix calculations and performance experiments

| Work | What it covers | Open solution |
| --- | --- | --- |
| [Matrix/vector timing lab](cpp/lab-01-firstSemestr/) | Matrix-vector products and timing experiments with `int`, `float` and `double`; writes `results.txt` | [Lab1.sln](cpp/lab-01-firstSemestr/Lab1.sln) |
| [Matrix homework](cpp/homework18-05-26/) | Matrix multiplication, transposition and multiplication using a transposed matrix | [Homework18-05-26.sln](cpp/homework18-05-26/Homework18-05-26.sln) |
| [SIMD experiments](cpp/SIMD/) | Scalar and vectorized matrix/vector calculations across related SSE and AVX/AVX2 projects | [SIMD.sln](cpp/SIMD/SIMD.sln) |

### Exam preparation and small exercises

| Work | What it covers | Open solution |
| --- | --- | --- |
| [A+B](cpp/A+B/) | Reading and adding two integers | [A+B.sln](cpp/A+B/A+B.sln) |
| [PZ](cpp/PZ/) | Array input and summation | [PZ.sln](cpp/PZ/PZ.sln) |
| [First-semester exam practice](cpp/task-on-exam-2-first-semestr/) | Digit arithmetic and a companion prime-counting exercise | [ProgrammingExam2Question.sln](cpp/task-on-exam-2-first-semestr/ProgrammingExam2Question.sln) |
| [Additional exam project copy](cpp/ProgrammingExam2Question/) | Another copy of the digit-arithmetic project, also linked to the prime-counting project | [ProgrammingExam2Question.sln](cpp/ProgrammingExam2Question/ProgrammingExam2Question.sln) |
| [Exam task 2](cpp/task-on-exam-2/) | Character-by-character stream input/output; usable with redirected input and output | [2taskOfExam.sln](cpp/task-on-exam-2/2taskOfExam.sln) |
| [Exam task 3](cpp/task-on-exam-3/) | Dynamic matrix transformation relative to the secondary diagonal | [3taskOfExam.sln](cpp/task-on-exam-3/3taskOfExam.sln) |
| [Language experiment](cpp/test/) | A small integer-arithmetic experiment, not an automated test suite | [test.sln](cpp/test/test.sln) |

## Related projects and folder organization

Some solutions contain several projects stored in neighbouring folders. These folders do **not** need a separate `.sln`: open the parent solution listed below and select the project you want to run.

| Parent solution | Related project folders |
| --- | --- |
| [Lab 03](cpp/lab-03/Lab3.sln) | [AB](cpp/AB/), [ABS](cpp/ABS/), [ABC](cpp/ABC/), [ABCD](cpp/ABCD/), [HIT](cpp/HIT/), [MENU](cpp/MENU/) |
| [Lab 04](cpp/lab-04/Lab4.sln) | [PRODUCT](cpp/PRODUCT/), [COUNTODD](cpp/COUNTODD/), [PARROT2](cpp/PARROT2/), [MENU2](cpp/MENU2/), [MAX](cpp/MAX/), [FIBO](cpp/FIBO/), [HIT2](cpp/HIT2/), [FACTOR](cpp/FACTOR/), [FACTOR2](cpp/FACTOR2/) |
| [Lab 06](cpp/lab-06/Lab6.sln) | [Lab6_2task](cpp/Lab6_2task/) — series summation and comparison with `ln(1 + x)` |
| [Lab 08](cpp/lab-08/Lab8.sln) | [Lab8v.2](cpp/Lab8v.2/) — file-input helper experiment; its example in `main` is currently commented out |
| [Lab 09](cpp/lab-09/Lab9.sln) | [task2](cpp/task2/) — custom string functions; [task3](cpp/task3/) — text-file processing |
| [Matrix homework](cpp/homework18-05-26/Homework18-05-26.sln) | [TransMatr](cpp/TransMatr/), [TransMatrOnUsualMatr](cpp/TransMatrOnUsualMatr/) |
| [SIMD experiments](cpp/SIMD/SIMD.sln) | [AVX](cpp/AVX/), [SIMDAVX](cpp/SIMDAVX/), [SIMDDDDDD](cpp/SIMDDDDDD/) |
| [First-semester exam practice](cpp/task-on-exam-2-first-semestr/ProgrammingExam2Question.sln) | [ProgrammingExam3Question](cpp/ProgrammingExam3Question/) — counting primes in an interval |

Original project names are retained so that relative paths in the Visual Studio solutions remain valid. Download or clone the **whole repository**, rather than an individual solution folder.

## Build and run

### Requirements

- Windows
- Visual Studio 2022 with the **Desktop development with C++** workload
- MSVC **v143** build tools and a compatible Windows SDK
- For vectorized experiments: a CPU supporting the instructions used by the selected project; AVX2 code requires AVX2 support

### Steps

1. Clone the repository:

   ```bash
   git clone https://github.com/Proggertopper/programming-labs.git
   cd programming-labs
   ```

2. Open a `.sln` file from the catalogue in Visual Studio.
3. If the solution contains several projects, right-click the desired project in **Solution Explorer** and choose **Set as Startup Project**.
4. Select a configuration and platform, for example **Debug | x64**.
5. Build the selected project and press **Ctrl + F5** to run without debugging.

If a toolset or SDK is missing, install the required Visual Studio component or retarget the project to a compatible installed version. For performance measurements, use **Release | x64** and compare equivalent build settings.

### Input files and console text

- Most applications accept input interactively. Prompts are primarily in Ukrainian; some exercises use English.
- Sample data is included where available, including [Lab 07 input](cpp/lab-07/input.txt) and [Lab 08 input](cpp/lab-08/input.txt).
- Relative filenames are resolved from the application's working directory. When running a file-based exercise in Visual Studio, set **Project Properties → Configuration Properties → Debugging → Working Directory** to `$(ProjectDir)`, or supply a suitable file path.
- Some programs use Windows console code-page settings. If Cyrillic text appears incorrectly, check the source encoding and console settings.

## Repository files

| File | Purpose |
| --- | --- |
| `.cpp` | C++ source code |
| `.sln` | Visual Studio solution; may group multiple projects |
| `.vcxproj` | Project settings and source-file references |
| `.vcxproj.filters` | File grouping inside Visual Studio |
| `.txt`, `.dat` | Exercise input or sample data, depending on the project |
| [`.gitignore`](.gitignore) | Excludes generated build files and local IDE settings |

Build outputs and machine-specific files such as `.vs/`, `Debug/`, `Release/`, `x64/`, `.exe`, `.obj` and `.vcxproj.user` should stay out of version control. Keep source code, project configuration and intentional sample data.

## Scope

These are educational projects, not a single application or a production library. They preserve coursework implementations, small experiments and some duplicate practice material. Input limits and error handling vary between exercises; experimental code may include commented alternatives.

The repository documents learning progress in programming fundamentals, algorithms, memory management and numerical computing. Benchmark results depend on hardware, compiler settings and input size; they are not universal performance claims.

## Author

**Oleksandr Kosynskyi** · Applied Mathematics student

- [GitHub](https://github.com/Proggertopper)
- [LinkedIn](https://www.linkedin.com/in/oleksandr-kosynskyi-java/)
