/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:56:03 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/10 19:44:35 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
// # include "../libft/libft.h"

typedef struct s_stack
{
    int             nbr;
    //long			index;
    struct s_stack *next;
    struct s_stack *prev;
}   n_stack;

void        ft_sa(n_stack **a, int j);
void        ft_sb(n_stack **b, int j);
void        ft_ss(n_stack **a, n_stack **b, int j);
void        ft_pb(n_stack **stack_a, n_stack **stack_b, int j);
void        ft_pa(n_stack **stack_a, n_stack **stack_b, int j);
void        ft_ra(n_stack **a, int j);
void        ft_rb(n_stack **b, int j);
void        ft_rr(n_stack **a, n_stack **b, int j);
void        ft_rra(n_stack **a, int j);
void        ft_rrb(n_stack **b, int j);
void        ft_rrr(n_stack **a, n_stack **b, int j);

n_stack     *ft_procces(int argc, char **argv);
n_stack     *ft_sub_process(char **argv);
void        ft_freestr(char **lst);
int         ft_checkdup(n_stack *a);

int         ft_checksort(n_stack *stack_a);
void        ft_sort(n_stack **stack_a);
n_stack     *ft_sort_b(n_stack **stack_a);
n_stack     **ft_sort_a(n_stack **stack_a, n_stack **stack_b);
void        ft_sort_three(n_stack **stack_a);
void	    ft_sort_b_till_3(n_stack **stack_a, n_stack **stack_b);
int         ft_rotate_type_ab(n_stack *a, n_stack *b);
int         ft_rotate_type_ba(n_stack *a, n_stack *b);
int         ft_case_rrarrb(n_stack *a, n_stack *b, int c);
int         ft_find_place_b(n_stack *stack_b, int nbr_push);
int         ft_find_place_a(n_stack *stack_a, int nbr_push);
int         ft_find_index(n_stack *st, int nbr);

int     	ft_case_rarb(n_stack *a, n_stack *b, int c);
int         ft_case_rrarrb(n_stack *a, n_stack *b, int c);
int         ft_case_rarrb(n_stack *a, n_stack *b, int c);
int         ft_case_rrarb(n_stack *a, n_stack *b, int c);

int         ft_case_rarb_a(n_stack *a, n_stack *b, int c);
int         ft_case_rrarrb_a(n_stack *a, n_stack *b, int c);
int         ft_case_rarrb_a(n_stack *a, n_stack *b, int c);
int         ft_case_rrarb_a(n_stack *a, n_stack *b, int c);

int         ft_apply_rarb(n_stack **a, n_stack **b, int c, char s);
int         ft_apply_rrarrb(n_stack **a, n_stack **b, int c, char s);
int         ft_apply_rarrb(n_stack **a, n_stack **b, int c, char s);
int         ft_apply_rrarb(n_stack **a, n_stack **b, int c, char s);

n_stack     *ft_lstlast(n_stack *lst);
int         ft_min(n_stack *a);
int         ft_max(n_stack *a);
int         ft_lstsize(n_stack *lst);

void        ft_error(void);
void        ft_free(n_stack **lst);

void        ft_add_back(n_stack **my_node, n_stack *stack_new);
n_stack     *ft_stack_new(int content);

int         ft_atoi2(const char *str);
int         ft_isdigit(int c);
char        **ft_split(char const *s, char c);
char        *ft_substr(char const *s, unsigned int start, size_t len);
size_t      ft_strlen(const char *str);

#endif