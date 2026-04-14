/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:27:09 by raphalme          #+#    #+#             */
/*   Updated: 2026/04/14 10:45:22 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks whether a character value is a valid ASCII byte.
 *
 * @param c Character value to test.
 * @return Non-zero if @p c is in [0, 127], 0 otherwise.
 */
int	ft_isascii(int c)
{
    return ((unsigned int)c < 128);
}
