
/*************************************************************************************
 *  File: kernel.h
 *  Copyright (c) 2023 Christian Zimmermann. All rights reserved
 *
 *************************************************************************************
 *  Master formula for the HVP contribution to a_mu:
 *
 *  a_mu = (alpha/pi)^2 * int_0^inf dt G(t) tilde{K}(t;m_mu)
 *
 *  tilde{K} is given by the function Ktilde(const double t, const double m_mu)
 *
 *  Definitions and expansion according to arXiv:1705.01775
 *
 ************************************************************************************/

#ifndef __hvpqedk_kernel_h__
#define __hvpqedk_kernel_h__

/* tilde{K}(t;m_mu) */
double Ktilde(const double t, const double m_mu);

/* m_mu^2 tilde{f}(t) */
double mu2_ft(const double t, const double m_mu);

/* expansion of tilde{f}(t) for th = m_mu * t < 1.05 */
double mu2_ft_small(const double th);

/* expansion of tilde{f}(t) for th = m_mu * t >= 1.05 */
double mu2_ft_large(const double th);

#endif
