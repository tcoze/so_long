/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:19:41 by tcoze             #+#    #+#             */
/*   Updated: 2023/11/14 20:39:50 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*out;

	out = malloc(sizeof(t_list));
	if (!out)
		return (NULL);
	out->content = content;
	out->next = NULL;
	return (out);
}
