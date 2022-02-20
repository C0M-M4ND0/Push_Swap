/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:38:46 by oabdelha          #+#    #+#             */
/*   Updated: 2022/02/20 10:55:00 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if (s1 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	l = ft_strlen(s2);
	temp = (char *)malloc(i + l + 1);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		temp[i++] = *s1++;
	while (*s2)
		temp[i++] = *s2++;
	temp[i] = '\0';
	return (temp);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sing;

	i = 0;
	result = 0;
	sing = 1;
	while ((str[i] == '\t') || (str[i] == '\r') || (str[i] == '\n')
		|| (str[i] == '\f') || (str[i] == '\v') || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sing *= -1;
		i++;
	}
	while ((str[i] - '0') >= 0 && (str[i] - '0') <= 9)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sing);
}

int	count_space(char *arg)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == 32)
			j++;
		i++;
	}
	return (j);
}

int	check_args(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_strlen(args[i]) == count_space(args[i]))
			return (1);
		i++;
	}
	return (0);
}
