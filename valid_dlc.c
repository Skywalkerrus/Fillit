/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_dlc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 20:15:51 by bantario          #+#    #+#             */
/*   Updated: 2019/07/19 16:57:45 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void	all_tonull(t_node *list)
{
	list->j = 1;
	list->fig = 0;
	list->t3_c[0] = 0;
	list->trig_one = 0;
	list->t3_c[1] = 0;
	list->sq = 0;
	list->i_g = 0;
	list->count_doc = 0;
	list->mas = ft_strnew(0);
}

void	shmon_symb(t_node *list, int fd)
{
	list->fdr = read(fd, list->mas, 3096);
	if (ft_strlen(list->mas) > 546)
		list->i_g++;
}

void	shmon_slesh(t_node *list)
{
	if (list->trig_one == 0)
		if (list->count_sn != 4)
			list->i_g++;
	if (list->trig_one == 2)
		if (list->count_sn != 5)
			list->i_g++;
	list->count_sn = 0;
	list->trig_one = 2;
	list->count_doc = 0;
}

void	valid_dlc(t_node *list)
{
	if (list->i_g > 0)
		return ;
	if ((list->fig ^ T2) == 0 || (list->fig ^ T6) == 0
			|| (list->fig ^ T10) == 0 || (list->fig ^ T12) == 0
			|| (list->fig ^ T17) == 0 || (list->fig ^ T19) == 0)
	{
		list->i_g++;
		return ;
	}
}

void	fresh(t_node *list)
{
	if (list->i_g > 0)
		return ;
	if ((list->fig ^ T1) == 0 || (list->fig ^ T2) == 0 || (list->fig ^ T3) == 0
			|| (list->fig ^ T4) == 0 || (list->fig ^ T5) == 0
			|| (list->fig ^ T6) == 0 || (list->fig ^ T7) == 0
			|| (list->fig ^ T8) == 0 || (list->fig ^ T9) == 0
			|| (list->fig ^ T10) == 0 || (list->fig ^ T11) == 0
			|| (list->fig ^ T12) == 0 || (list->fig ^ T13) == 0
			|| (list->fig ^ T14) == 0 || (list->fig ^ T15) == 0
			|| (list->fig ^ T16) == 0 || (list->fig ^ T17) == 0
			|| (list->fig ^ T18) == 0 || (list->fig ^ T19) == 0)
	{
		shmon_slesh(list);
		list->fis[list->j] = list->fig;
		if ((list->fig ^ T15) == 0)
			list->sq++;
		list->fis[0] = list->t3_c[1];
		list->j++;
	}
	else
	{
		list->i_g++;
		return ;
	}
	list->fig = 0;
}
