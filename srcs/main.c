/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarliah <lkarliah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:50:14 by natali            #+#    #+#             */
/*   Updated: 2021/09/02 20:43:20 by lkarliah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	g_data.status = 0;
	g_data.sig_pid = 0;
	set_sig();
	tcgetattr(0, &g_data.termset);
	setup_term();
	tputs(tgetstr("cl", 0), 1, output_func);
	ft_putstr_fd("\033[1;32mWELCOME TO MY BASH\n\033[0m", 1);
	env_get(envp);
	shlvl_set();
	hist_create();
	input();
	dlist_free(g_data.history.hist_start);
	close(g_data.history.hist_fd);
	env_free(g_data.env);
}
