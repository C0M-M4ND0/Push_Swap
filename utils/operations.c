/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:49:07 by oabdelha          #+#    #+#             */
/*   Updated: 2022/02/08 13:36:10 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_list **list_a, int order)
{
	t_list	*temp;
	int		swap;

	if (ft_lstsize(*list_a) > 1)
	{
		temp = (*list_a)->next;
		swap = temp->content;
		temp->content = (*list_a)->content;
		(*list_a)->content = swap;
		if (order == 1)
			ft_putendl_fd("sa");
	}
}

void	swap_b(t_list **list_b, int order)
{
	t_list	*temp;
	int		swap;

	if (ft_lstsize(*list_b) > 1)
	{
		temp = (*list_b)->next;
		swap = temp->content;
		temp->content = (*list_b)->content;
		(*list_b)->content = swap;
		if (order == 1)
			ft_putendl_fd("sb");
	}
}

void	push_a(t_list **list_a, t_list **list_b, int order)
{
	int	temp;

	if (ft_lstsize(*list_b) > 0)
	{
		temp = (*list_b)->content;
		ft_lstadd_front(list_a, ft_lstnew(temp));
		ft_lstdelone(list_b);
		if (order == 1)
			ft_putendl_fd("pa");
	}
}

void	push_b(t_list **list_b, t_list **list_a, int order)
{
	int	temp;

	if (ft_lstsize(*list_a) > 0)
	{
		temp = (*list_a)->content;
		if (*list_b == NULL)
			*list_b = ft_lstnew(temp);
		else
			ft_lstadd_front(list_b, ft_lstnew(temp));
		ft_lstdelone(list_a);
		if (order == 1)
			ft_putendl_fd("pb");
	}
}

void	rotate_a(t_list **list_a, int order)
{
	int	temp;

	if (ft_lstsize(*list_a) > 1)
	{
		temp = (*list_a)->content;
		ft_lstadd_back(list_a, ft_lstnew(temp));
		ft_lstdelone(list_a);
		if (order == 1)
			ft_putendl_fd("ra");
	}
}
