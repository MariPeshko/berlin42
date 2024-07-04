/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:56:03 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/11 19:47:04 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	ft_sa(t_stack **a, int j);
void	ft_sb(t_stack **b, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_pb(t_stack **a, t_stack **b, int j);
void	ft_pa(t_stack **a, t_stack **b, int j);
void	ft_ra(t_stack **a, int j);
void	ft_rb(t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rra(t_stack **a, int j);
void	ft_rrb(t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);

t_stack	*ft_procces(int argc, char **argv);
t_stack	*ft_sub_process(char **argv);
void	ft_freestr(char **lst);
int		dup_search(t_stack *a);

int		ft_checksort(t_stack *stack_a);
void	ft_sort(t_stack **stack_a);
t_stack	*ft_sort_b(t_stack **stack_a);
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack_a);
void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
int		ft_rotate_type_ab(t_stack *a, t_stack *b);
int		ft_rotate_type_ba(t_stack *a, t_stack *b);
int		ft_case_rrarrb(t_stack *a, t_stack *b, int c);
int		ft_find_place_b(t_stack *stack_b, int nbr_push);
int		ft_find_place_a(t_stack *stack_a, int nbr_push);
int		ft_find_index(t_stack *st, int nbr);

int		ft_case_rarb(t_stack *a, t_stack *b, int c);
int		ft_case_rrarrb(t_stack *a, t_stack *b, int c);
int		ft_case_rarrb(t_stack *a, t_stack *b, int c);
int		ft_case_rrarb(t_stack *a, t_stack *b, int c);

int		ft_case_rarb_a(t_stack *a, t_stack *b, int c);
int		ft_case_rrarrb_a(t_stack *a, t_stack *b, int c);
int		ft_case_rarrb_a(t_stack *a, t_stack *b, int c);
int		ft_case_rrarb_a(t_stack *a, t_stack *b, int c);

int		ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);

t_stack	*ft_lstlast(t_stack *lst);
int		ft_min(t_stack *a);
int		ft_max(t_stack *a);
int		ft_lstsize(t_stack *lst);

void	ft_error(void);
void	ft_error_mix(void);
void	ft_free(t_stack **stack);
void	mix_str_int(char *argv, t_stack **a);

void	ft_add_back(t_stack **my_node, t_stack *stack_new);
t_stack	*ft_stack_new(int content);

int		ft_atoi2(const char *str, t_stack **my_node);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

#endif