/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:29:07 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/10 19:29:11 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // write
#include <stdio.h>  // printf
#include <stdlib.h> // atoi

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

int main(int argc, char **argv)
{
    n_stack *a;

    a = ft_procces(argc, argv);
    if (!a || ft_checkdup(a))
    {
        ft_free(&a);
        ft_error();
    }
    if (!ft_checksort(a))
        ft_sort(&a);

    int check;
    check = ft_checksort(a);
    if (check == 1)
        printf("Numbers are sorted!\n");
    if (check == 2)
        printf("There is only 1 number\n");
    if (check == 0)
        printf("Oh no! Numbers are not sorted\n");

    n_stack *ptr = NULL;
    ptr = a;
    int i = 1;
    while (ptr != NULL)
    {
        printf("%d node of a_stack is %d\n", i, ptr->nbr);
        ptr = ptr->next;
        i++;
    }
    ft_free(&a);
    free(a);
    a = NULL;
    return (0);
}
