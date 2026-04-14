/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:41:00 by raphalme          #+#    #+#             */
/*   Updated: 2026/04/14 11:00:51 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Sets a memory area to zero bytes.
 *
 * @param void_ptr Pointer to the memory block.
 * @param n Number of bytes to zero.
 */
void	ft_bzero(void *void_ptr, size_t n)
{
	ft_memset(void_ptr, 0, n);
}
