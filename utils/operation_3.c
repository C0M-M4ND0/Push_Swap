/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:17:47 by oabdelha          #+#    #+#             */
/*   Updated: 2022/02/08 13:36:05 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a_and_b(t_list **list_a, t_list **list_b, int order)
{
	int	ord;

	ord = -1;
	if (ft_lstsize(*list_a) > 1 && ft_lstsize(*list_b) > 1)
	{
		swap_a(list_a, ord);
		swap_b(list_b, ord);
		if (order == 1)
			ft_putendl_fd("ss");
	}
}
