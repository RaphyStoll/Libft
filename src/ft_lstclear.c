/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:21:00 by raphalme          #+#    #+#             */
/*   Updated: 2026/04/14 10:36:21 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/types.h"

/**
 * @brief Clears a linked list.
 * This function takes a pointer to the first element of a linked list and a
 * function pointer to a deletion function, then removes and frees all elements
 * in the list.
 *
 * @param lst A pointer to the pointer to the first element of the list.
 * @param del A function pointer to the deletion function.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
