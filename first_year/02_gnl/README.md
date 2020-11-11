# Get Next Line

## Description
>Whether it's a file, standard input or even later from a network connection, you're always going to read some content line by line. It's time to make this function, indispensable for certain projects.

## Objectives
* Filedescriptors
* Bufferisation
* Basic Parsing

## Skills
* Imperative programming
* Rigor
* Algorithms & AI

## Usage
prototype : `int get_next_line(const int fd, char **line);`</br>
```
while(get_next_line(1, line))
{
	ft_putstr(line);
	ft_putchar('\n');
	free(line);
}
```