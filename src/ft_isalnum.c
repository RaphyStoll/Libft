/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:25:22 by raphalme          #+#    #+#             */
/*   Updated: 2026/04/14 11:01:24 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks whether a character is alphanumeric.
 *
 * @param c Character value to test.
 * @return Non-zero if @p c is a letter or a digit, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	return (((unsigned int)(c - '0') < 10)
		|| ((unsigned int)((c | 32) - 'a') < 26));
}
