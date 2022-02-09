/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:41:43 by oabdelha          #+#    #+#             */
/*   Updated: 2022/02/08 13:36:12 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operation_in_stack_a(t_list **list_a,
			t_list **list_b, int len, int order)
{
	int	mid;
	int	temp;
	int	i;

	i = 0;
	temp = len;
	if (len <= 1 || is_sorted_a(*list_a) == 1)
		return ;
	mid = put_in_arry(*list_a, list_a, list_b, len);
	while (temp > (len / 2 + len % 2))
	{
		if (mid > (*list_a)->content)
		{
			push_b(list_b, list_a, order);
			temp--;
		}
		else if (++i)
			rotate_a(list_a, order);
	}
	while (i-- > 0 && ft_lstsize(*list_a) > (len / 2 + len % 2))
		reverse_rotate_a(list_a, order);
	operation_in_stack_a(list_a, list_b, (len / 2 + len % 2), order);
	operation_in_stack_b(list_b, list_a, (len / 2), order);
}

void	operation_in_stack_b(t_list **list_b,
			t_list **list_a, int len, int order)
{
	int	mid;
	int	temp;
	int	i;

	i = 0;
	if (len < 4)
		return (sort_rev_ord(list_b, list_a, len, order));
	temp = len;
	mid = put_in_arry(*list_b, list_a, list_b, len);
	while (temp > (len / 2))
	{
		if (mid <= (*list_b)->content)
		{
			push_a(list_a, list_b, order);
			temp--;
		}
		else if (++i)
			rotate_b(list_b, order);
	}
	while (i-- > 0 && ft_lstsize(*list_b) > 1
		&& ft_lstsize(*list_b) > (len / 2))
		reverse_rotate_b(list_b, order);
	operation_in_stack_a(list_a, list_b, (len / 2 + len % 2), order);
	operation_in_stack_b(list_b, list_a, (len / 2), order);
}
