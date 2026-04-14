/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:35:00 by raphalme          #+#    #+#             */
/*   Updated: 2026/04/14 10:45:22 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks whether a character is printable in ASCII.
 *
 * @param c Character value to test.
 * @return Non-zero if @p c is in [32, 126], 0 otherwise.
 */
int	ft_isprint(int c)
{
	return ((unsigned int)(c - 32) < 95);
}
