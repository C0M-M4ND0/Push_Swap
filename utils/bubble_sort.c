/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:40:58 by oabdelha          #+#    #+#             */
/*   Updated: 2022/02/08 13:35:37 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swaping(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

void	bubble_sort(int *arry, int n)
{
	int	i;
	int	j;

	j = 0;
	while (j < n)
	{
		i = n - 1;
		while (i > j)
		{
			if (arry[i] < arry[i - 1])
			{
				swaping(&arry[i], &arry[i - 1]);
			}
			i--;
		}
		j++;
	}
}
