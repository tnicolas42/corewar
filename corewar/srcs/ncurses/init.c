/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 12:35:13 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/22 15:23:02 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | init.c                                                   |
**   |     ft_init_windows_1(23 lines)                          |
**   |     ft_init_windows_2(19 lines)                          |
**   |     ft_init(15 lines)                                    |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <corewar.h>

static void	ft_init_windows_1(t_a *a)
{
	int		i;
	int		moins_i;

	if (!(a->nc.win_info = subwin(stdscr, WIN_H, WIN_W, 0,
			a->nc.sqrt_mem_size * 3 + 4)))
		error_init_src(a);
	i = -1;
	while (++i < a->num_of_player && WIN_H * (i + 1) - i - 1 +
			WIN_H <= a->nc.sqrt_mem_size + 3)
		if (!(a->nc.win_player[i] = subwin(stdscr, WIN_H, WIN_W, WIN_H
						* (i + 1) - i - 1, a->nc.sqrt_mem_size * 3 + 4)))
			error_init_src(a);
	moins_i = --i - 1;
	if (a->nc.sqrt_mem_size * 3 + 5 + WIN_W * 2 < COLS)
	{
		while (++i < a->num_of_player)
			if (!(a->nc.win_player[i] = subwin(stdscr, WIN_H, WIN_W, (WIN_H
					- 1) * (i - moins_i), a->nc.sqrt_mem_size * 3 + 3 + WIN_W)))
				error_init_src(a);
	}
	else
		while (++i < a->num_of_player)
			if (!(a->nc.win_player[i] = subwin(stdscr, WIN_H, WIN_W,
					a->nc.sqrt_mem_size + 2, (WIN_W - 1) * (i - moins_i))))
				error_init_src(a);
}

static void	ft_init_windows_2(t_a *a)
{
	int		i;
	int		moins_i;

	if (!(a->nc.win_info = subwin(stdscr, WIN_H, WIN_W,
					a->nc.sqrt_mem_size + 2, 0)))
		error_init_src(a);
	i = -1;
	while (++i < a->num_of_player)
		if (WIN_W * (i + 1) - i - 1 + WIN_W <= a->nc.sqrt_mem_size * 3 + 5)
		{
			if (!(a->nc.win_player[i] = subwin(stdscr, WIN_H, WIN_W,
					a->nc.sqrt_mem_size + 2, WIN_W * (i + 1) - i - 1)))
				error_init_src(a);
		}
		else
			break ;
	moins_i = --i;
	while (++i < a->num_of_player)
	{
		if (!(a->nc.win_player[i] = subwin(stdscr, WIN_H,
						WIN_W, a->nc.sqrt_mem_size
				+ 2 + WIN_H - 1, (WIN_W - 1) * (i - moins_i - 1))))
			error_init_src(a);
	}
}

static int	ft_testmalloc(t_a *a)
{
	int i;

	if (a->nc.win_mem == NULL || a->nc.win_info == NULL)
		return (ERROR);
	i = -1;
	while (++i < a->num_of_player)
		if (a->nc.win_player[i] == NULL)
			return (ERROR);
	return (SUCCESS);
}

void		ft_init(t_a *a)
{
	a->nc.win_mem = NULL;
	a->nc.win_info = NULL;
	initscr();
	start_color();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	a->nc.color = ft_init_color();
	a->nc.sqrt_mem_size = sqrt(MEM_SIZE);
	if (!(a->nc.win_mem = subwin(stdscr, a->nc.sqrt_mem_size + 3,
			a->nc.sqrt_mem_size * 3 + 5, 0, 0)))
		error_init_src(a);
	if (a->nc.sqrt_mem_size * 3 + 5 + WIN_W < COLS)
		ft_init_windows_1(a);
	else
		ft_init_windows_2(a);
	if (ft_testmalloc(a) == ERROR)
		error_malloc(a);
}
