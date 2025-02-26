/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mborsuk <mborsuk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/08 15:06:51 by mborsuk       #+#    #+#                 */
/*   Updated: 2025/02/08 15:07:03 by mborsuk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;

	p = str;
	while (n > 0)
	{
		*p++ = c;
		n--;
	}
	return (str);
}
