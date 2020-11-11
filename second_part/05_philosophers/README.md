# Philosophers

## Description
>This project is an introduction to threading, process and how to deal with shared memory.

## Objectives
* Multi threading
* Mutex
* Semaphore
* Process

## Skills
* Imperative programming
* Rigor
* Unix

## Usage
For each philo_(one|two|three) you need to `make` then `./philo_(one|two|three)` will display the usage.</br>
Example : `./philo_one 4 310 200 100 50`

## Specification
* philo one used one thread per philosopher and forks are protected with mutexes
* philo two used one thread per philosopher and forks are represented with a semaphore
* philo three used one process per philosopher and forks are represented with a semaphore
