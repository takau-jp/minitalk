/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:32:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 22:36:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stdint.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif
# define DEG_TO_RAD 0.01745329251994329547 // (M_PI / 180.0)
# define RAD_TO_DEG 57.29577951308232286465 // (180.0 / M_PI)

double		ft_fabs(double x);
int			ft_rand_r(unsigned int *seed);
double		ft_round(double x);
double		ft_sqrt(double x);
uint32_t	ft_xorshift(uint32_t *seed);

#endif
