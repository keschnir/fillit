/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_solution.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/17 14:39:09 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:02:15 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_solution(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->grid_size)
	{
		ft_putendl(env->grid[i]);
		i++;
	}
}
