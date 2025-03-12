/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:37:24 by amsbai            #+#    #+#             */
/*   Updated: 2025/03/03 15:27:11 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_realloc(void *str, size_t newsize)
{
	char	*newptr;

	if (str == 0)
		return (malloc(newsize));
	if (newsize == 0)
	{
		free (str);
		return (NULL);
	}
	newptr = malloc(newsize);
	if (!newptr)
		return (NULL);
	ft_memmove(newptr, str, newsize);
	free(str);
	return (newptr);
}
