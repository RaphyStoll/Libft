/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:19:00 by raphalme          #+#    #+#             */
/*   Updated: 2026/04/14 10:36:21 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/types.h"

/**
 * @brief Adds a new element to the end of a linked list.
 * This function takes a pointer to the first element of a linked list and a new
 * element, then adds the new element to the end of the list. If the list is
 * empty, the new element becomes the first element.
 *
 * @param lst A pointer to the pointer to the first element of the list.
 * @param new The new element to add to the end of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
