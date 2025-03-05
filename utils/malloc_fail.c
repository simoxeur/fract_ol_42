/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_fail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:47:23 by mtalbi            #+#    #+#             */
/*   Updated: 2024/05/15 14:38:43 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	malloc_fail(void)
{
	putstr_fd("\033[0;31mmalloc failed to allocate memory\n", 2);
	exit(EXIT_FAILURE);
}
