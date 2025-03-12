/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:04:07 by amsbai            #+#    #+#             */
/*   Updated: 2025/03/03 20:14:48 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*srcc;

	dest = (char *)dst;
	srcc = (char *)src;
	if (src == dst || len == 0)
	{
		return (dst);
	}
	if (srcc > dest)
	{
		return (ft_memcpy(dst, src, len));
	}
	else
	{
		while (len-- > 0)
		{
			dest[len] = srcc[len];
		}
	}
	return (dst);
}
