/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:35:16 by dleong            #+#    #+#             */
/*   Updated: 2017/10/29 19:08:15 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_bzero(char *s, size_t n)
{
	char	*result;
	size_t	i;

	result = s;
	i = 0;
	while (i < n)
	{
		result[i] = 0;
		i++;
	}
}
