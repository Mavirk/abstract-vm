/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:40:22 by rmurdoch          #+#    #+#             */
/*   Updated: 2018/07/21 14:08:23 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>

int main(){
	std::string lineIn;
	std::cin >> lineIn; 

	while (1)
		std::cin >> lineIn;
		switch(lineIn){
			case exit:
		}
	if (lineIn == "exit"){
		std::cout << "exit was called";
	}		
}
