/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:56 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/10/25 12:35:57 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_free(void)
{
	my_malloc(2, 1);
}

void	destroy(t_gdata **g_data)
{
	t_gdata	*data;

	data = *g_data;
	while (g_data && *g_data)
	{
		data = (*g_data)->next;
		free((*g_data)->data);
		free(*g_data);
		*g_data = data;
	}
	
}

void    *my_malloc(size_t size, int free_mode)
{
    static t_gdata	*g_data;
    t_gdata			*new;

    if (!free_mode)
    {
		new = malloc(sizeof (t_gdata));
		if (!new)
			return (destroy(&g_data), NULL);
		new->data = malloc(size);
		if (!new->data)
			return (destroy(&g_data), NULL);
		new->next = g_data;
		g_data = new;
		return (new->data);
    }
	else
		return (destroy(&g_data), NULL);
}