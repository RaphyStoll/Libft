/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:20:00 by raphalme          #+#    #+#             */
/*   Updated: 2026/04/14 10:36:21 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/types.h"

/**
 * @brief Deletes and frees a single element from a linked list.
 * This function takes an element from a linked list and a function pointer to a
 * deletion function, then removes and frees the element.
 *
 * @param lst The element to delete and free.
 * @param del A function pointer to the deletion function.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
