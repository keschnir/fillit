/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_test_input.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/17 14:39:34 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:09:00 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_valid_count(char *tetri)
{
	int		count_full;
	int		count_empt;
	int		count_retu;

	count_full = 0;
	count_empt = 0;
	count_retu = 0;
	while (*tetri)
	{
		if (*tetri == '#')
			count_full++;
		if (*tetri == '.')
			count_empt++;
		if (*tetri == '\n')
			count_retu++;
		tetri++;
	}
	if ((count_full != 4)
		|| (count_empt != 12)
		|| (count_retu != 4))
		EXIT;
}

void	ft_valid_length(char *tetri)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if ((i % 5) < 4)
		{
			if (!(tetri[i] == '#' || tetri[i] == '.'))
				EXIT;
		}
		else if (!(tetri[i] == '\n'))
			EXIT;
		i++;
	}
}

int		ft_element_is_valid(char **elements, char *subject)
{
	int i;
	int	ret;

	i = 4;
	ret = 0;
	while (i--)
	{
		if (subject + 1 == elements[i])
			ret += 1;
		else if (subject + 5 == elements[i])
			ret += 1;
	}
	return (ret);
}

void	ft_valid_figure(char *tetri)
{
	char	*elements[4];
	int		i;
	int		valid;

	i = 0;
	while (*tetri)
	{
		if (*tetri == '#')
			elements[i++] = tetri;
		tetri++;
	}
	i = 0;
	valid = 0;
	while (i < 4)
	{
		valid += ft_element_is_valid(elements, elements[i]);
		i++;
	}
	if (valid < 3)
		EXIT;
}

void	ft_test_input(char *file_name)
{
	char	tetri[21];
	int		read_ret;
	int		fd;

	ft_bzero(tetri, 21);
	read_ret = 1;
	fd = open(file_name, O_RDONLY);
	while (read_ret == 1)
	{
		read_ret = read(fd, tetri, 20);
		ft_valid_count(tetri);
		ft_valid_length(tetri);
		ft_valid_figure(tetri);
		read_ret = read(fd, tetri, 1);
		if (read_ret && *tetri != '\n')
			EXIT;
	}
	if (read_ret == -1)
		EXIT;
	close(fd);
}
