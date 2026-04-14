/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:16:29 by raphalme          #+#    #+#             */
/*   Updated: 2026/04/14 11:01:03 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks whether a character is alphabetic.
 *
 * @param c Character value to test.
 * @return Non-zero if @p c is in [A-Z] or [a-z], 0 otherwise.
 */
int	isalpha(int c)
{
	return (((unsigned int)(c | 32) - 'a') < 26);
}
