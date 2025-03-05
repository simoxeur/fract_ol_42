/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:05:30 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/14 19:27:02 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	putstr_fd(char *str, int fd);
int		ft_strncmp(char *s1, char *s2, int n);
void	malloc_fail(void);
double	atoa_double(char *str);

#endif