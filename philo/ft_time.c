/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:55:17 by icastell          #+#    #+#             */
/*   Updated: 2022/03/29 20:01:22 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t    ft_timestamp(void)
{
    struct timeval t;

    gettimeofday(&t, NULL);
    return(t.tv_sec * 1000 + t.tv_usec / 1000);
}