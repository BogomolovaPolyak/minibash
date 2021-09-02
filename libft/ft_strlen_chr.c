/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarliah <lkarliah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:34:07 by lkarliah          #+#    #+#             */
/*   Updated: 2021/06/04 18:48:24 by lkarliah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen_chr(const char *s, char c)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != c && s[i])
			i++;
	}
	return (i);
}
