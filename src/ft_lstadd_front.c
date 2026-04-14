/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:16:00 by raphalme          #+#    #+#             */
/*   Updated: 2026/04/14 10:36:21 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"

/**
 * @brief Adds a new element to the front of a linked list.
 * This function takes a pointer to the first element of a linked list and a new
 * element, then adds the new element to the front of the list. The new element
 * becomes the new head of the list.
 *
 * @param lst A pointer to the pointer to the first element of the list.
 * @param new The new element to add to the front of the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
