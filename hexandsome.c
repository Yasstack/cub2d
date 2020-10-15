/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexandsome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:51:47 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/10/14 19:17:12 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

void		ft_fhexa(int nb, t_mapdata *map)
{
	static int	i = 0;
	char		*xa;

	xa = "0123456789abcdef";
	FLOOR[i] = xa[nb / 16];
	i++;
	FLOOR[i] = xa[nb % 16];
	i++;
}

void		ft_chexa(int nb, t_mapdata *map)
{
	static int	i = 0;
	char		*xa;

	xa = "0123456789abcdef";
	CEELING[i] = xa[nb / 16];
	i++;
	CEELING[i] = xa[nb % 16];
	i++;
}

double		colmdist(t_mapdata *map, t_horizontal *it)
{
	double dist;
	double hdist;
	double vdist;

	rayfacing(it);
	hdist = ft_horizontal(map, it);
	vdist = ft_vertical(map, it);
	if (hdist < vdist)
	{
		// WALLX = WALLHX;
		// WALLY = WALLHY;
		dist = hdist;
		// HH = 1;
	}
	else
	{
		// WALLX = WALLVX;
		// WALLY = WALLVY;
		dist = vdist;
		// HV = 1;
	}
	return (dist);
}

void		init(t_horizontal *it)
{
	it->dx = 0;
	it->x = 0;
	it->wallx = 0;
	it->dy = 0;
	it->y = 0;
	it->wally = 0;
	it->facedown = 0;
	it->faceup = 0;
	it->faceleft = 0;
	it->faceright = 0;
}
