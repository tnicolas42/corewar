/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:35:14 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/07 16:25:30 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_error.c                                               |
**   |     ft_err_msg(4 lines)                                  |
**   |     ft_warning_msg(4 lines)                              |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <corewar.h>

int			ft_err_msg(t_a *a, t_line *new_ln, char *txt)
{
	ft_errprintf("\t{red}{bold}ERROR:{eoc} {yellow}%s.s\n{eoc}"
			"\t\t{yellow}{bold}line: %d{eoc} ->{bold} %s{eoc}\n"
			"\t\t%s\n", a->file_name, new_ln->num_line, txt, new_ln->line);
	return (ERROR);
}

int			ft_warning_msg(t_a *a, t_line *new_ln, char *txt)
{
	ft_errprintf("\t{magenta}{bold}WARNING:{eoc} {yellow}%s.s\n{eoc}"
			"\t\t{yellow}{bold}line: %d{eoc} ->{bold} %s{eoc}\n"
			"\t\t%s\n", a->file_name, new_ln->num_line, txt, new_ln->line);
	return (SUCCESS);
}