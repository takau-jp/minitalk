/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:25:09 by stanaka2          #+#    #+#             */
/*   Updated: 2025/08/28 02:03:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(void) {
    // size_t  count = 1000;
    // int pid = getpid();
    // printf("%d\n", pid);
    // while (count--)
    // {
    //     write(1, "a", 1);
    // }
    // char *test;
    // test = strdup("test\033[2J\033[3J");
    // write(1, test, strlen(test));
    // while (*test)
    // {
    //     write(1, test++, 1);
    // }
    write(1, "あ", 2);
}