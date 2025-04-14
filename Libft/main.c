/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:59:49 by klino-an          #+#    #+#             */
/*   Updated: 2025/04/14 19:32:38 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
    char str[] = "banana, uva, maca, pera";
    char **matriz = ft_split(str, ',');
   printf("%s", matriz[0]);
}
