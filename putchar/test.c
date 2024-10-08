/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            О функциях в Си                                 */
/*                                                                            */
/*                  https://metanit.com/cpp/c/4.1.php                         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>				/* Эта библиотека требуется для использования функции write */



void 	ft_putchar(char c);		/* Обьявляем функцию написав прототип для того чтобы при компиляции программы
								** компилятор мог знать о функции до ее вызова.
								** Прототип состоит из 3 частей.
								** 1. Вначале указывается возвращаемый тип функции. Если функция не возвращает
								** никакого значения(как у нас), то используется тип 'void'.
								** 2. Затем идет имя функции(у нас это 'ft_putchar'), которое представляет
								** произвольный идентификатор, к которому применяются те же правила, что и
								** к именованию переменных.
								** 3. После имени функции, в скобках, указываем аргументы функции, с которыми
								** функция должна выполнить какие  либо действия - у нас это один аргумент
								** 'char c'. Где 'char' это тип данных, которые принимает в себя переменная
								** 'c'. */

void	ft_putchar(char c)		/* Определяем саму функцию, описывая её тело, в котором мы вызываем функцию 'write'
								** для печати символа принимаемого в переменную 'c'(аргумент функции) */
{
    write(1, &c, 1);			/* Вызываем функцию 'write'(системный вызов) отправляя ей в аргументы идетификатор
								** стандартного потока вывода, котрый будет использован для отправки туда символа на печать.
								** Далее мы используем оператор взятия адреса '&', чтобы мы могли взять адресс переменной 'c'
								** и отправить этот в функцию 'write' для печати содержимого переменной на которую указывает
								** этот адресс.
								** В последнем аргументе функции 'write' мы указываем то на сколько байт в право от добытого
								** нами адреса нужно продвинуться и сколько считать данных, чтобы их отправить на печать через
								** стандартный поток вывода используя его идентификатор(файловый дескриптор) который мы указали
								** в первом аргументе функции 'write' */
}

/* ************************************************************************** */
/* ************************************************************************** **
**
** Функция write имеет следующие параметры:
**    write(<дескриптор потока>, <&указатель на буфер>, <число записыв. байтов>):
**
**
** 1. int <дескриптор(идентификатор) потока ввода/вывода>:
**     0    –  stdin, стандартное устройство ввода (клавиатура);
**     1    –  stdout, стандартное устройство вывода (экран);
**     2    –  stderr, стандартное устройство вывода сообщения об ошибках (также экран).
** Простыми словами. При открытии файла операционная система создает запись для
** представления этого файла и сохраняет информацию об этом открывшемся файле.
** Итак, если в вашей ОС открыто 100 файлов, то в ОС будет находиться 100
** записей (где-то в ядре). Эти записи представлены целыми числами такими
** как (... 100, 101, 102....). Этот номер записи является файловым дескриптором.
** Таким образом, это просто целое число, которое уникально представляет
** собой открытый файл в операционной системе. Если ваш процесс откроет
** 10 файлов, ваша таблица процессов будет содержать 10 записей для
** дескрипторов файлов. Еще простыми словами: чтобы попасть в город
** (прочитать/записать в файл) мы едем через мост (дескриптор).
**
**
** 2. const void *buf <указатель на буфер> - адрес, куда мы будем записывать наши данные (байты) и возращать их.
** Значение из ft_putchar(char c(отсюда)) передав его в write(1, &c(cюда), 1).
** Синтаксис, когда мы делаем ссылку на адрес с → &c.
**
**
** 3. size_t count <число записываемых байтов> - количество пересылаемых данных (1 byte - 1 char).
** Эта функция записывает один символ в стандартный поток вывода терминала.
**
** ************************************************************************** */
/* ************************************************************************** */



int		main(void)				/* Определяем основную функцию, с которой начнется выполнение программы.
								** 'void' в аргументах основной функции означает, что эта функция не принимает
								** в аргументы ничего. 'int' в начале функции говорит о том что функция перед
								** завершением возвращает целое число */
{
    ft_putchar(':');			/* Вызываем созданную нами функцию 'ft_putchar' для проверки несколько раз.
								** P.S. Cимволы одинарных кавычек  используются для того чтобы обрамлять отдельные
								** символы(например так 'H', 'e', 'l', 'l', 'o'), а  символы двойных кавычек используются
								** для того чтобы обрамлять целые строки (например так "Hello"). Не путайте их. */
    ft_putchar(')');
    ft_putchar('\n');
    return (0);					/* Для возвращения результата функция применяет оператор 'return'. В данном случае он возвращает ноль.
								** Здесь он нужен для отладки - чтобы показать что если функция вернула 0 после работы значит она дошла до конца,
								** а это значит что все прошло гладко */
}