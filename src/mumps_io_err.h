/*
 *
 *  This file is part of MUMPS 5.0.0, released
 *  on Fri Feb 20 08:19:56 UTC 2015
 *
 *
 *  Copyright 1991-2015 CERFACS, CNRS, ENS Lyon, INP Toulouse, Inria,
 *  University of Bordeaux.
 *
 *  This version of MUMPS is provided to you free of charge. It is
 *  released under the CeCILL-C license,
 *  http://www.cecill.info/licences/Licence_CeCILL-C_V1-en.html, 
 *  except for the external and optional ordering PORD, 
 *  in separate directory PORD, which is public domain (see PORD/README).
 *
 *  You can acknowledge (using references [1] and [2]) the contribution of
 *  this package in any scientific publication dependent upon the use of
 *  the package. Please use reasonable endeavours to notify the authors
 *  of the package of this publication.
 *
 *   [1] P. R. Amestoy, I. S. Duff, J. Koster and  J.-Y. L'Excellent,
 *   A fully asynchronous multifrontal solver using distributed dynamic
 *   scheduling, SIAM Journal of Matrix Analysis and Applications,
 *   Vol 23, No 1, pp 15-41 (2001).
 *
 *   [2] P. R. Amestoy, A. Guermouche, J.-Y. L'Excellent and
 *   S. Pralet, Hybrid scheduling for the parallel solution of linear
 *   systems. Parallel Computing Vol 32 (2), pp 136-156 (2006).
 *
 *  As a counterpart to the access to the source code and rights to copy,
 *  modify and redistribute granted by the license, users are provided only
 *  with a limited warranty  and the software's author,  the holder of the
 *  economic rights,  and the successive licensors  have only  limited
 *  liability. 
 *
 *  In this respect, the user's attention is drawn to the risks associated
 *  with loading,  using,  modifying and/or developing or reproducing the
 *  software by the user in light of its specific status of free software,
 *  that may mean  that it is complicated to manipulate,  and  that  also
 *  therefore means  that it is reserved for developers  and  experienced
 *  professionals having in-depth computer knowledge. Users are therefore
 *  encouraged to load and test the software's suitability as regards their
 *  requirements in conditions enabling the security of their systems and/or 
 *  data to be ensured and,  more generally, to use and operate it in the 
 *  same conditions as regards security. 
 *
 *  The fact that you are presently reading this means that you have had
 *  knowledge of the CeCILL-C license and that you accept its terms.
 *
 */
#include <errno.h>
#include "mumps_common.h"
#include "mumps_c_types.h"
#if ! ( defined(MUMPS_WIN32) || defined(WITHOUT_PTHREAD) )
# include <pthread.h>
#endif /* ! ( MUMPS_WIN32 || WITHOUT_PTHREAD ) */
#if ! ( defined(MUMPS_WIN32) || defined(WITHOUT_PTHREAD) )
extern pthread_mutex_t err_mutex;
#endif /* ! ( MUMPS_WIN32 || WITHOUT_PTHREAD ) */
/* Exported functions */
#define MUMPS_LOW_LEVEL_INIT_ERR_STR \
    F_SYMBOL(low_level_init_err_str,LOW_LEVEL_INIT_ERR_STR)
void MUMPS_CALL
MUMPS_LOW_LEVEL_INIT_ERR_STR( MUMPS_INT *dim, char *err_str, mumps_ftnlen l1 );
/* Export an error to the Fortran layer
   Returns mumps_errno for convenience */
MUMPS_INT mumps_io_error(MUMPS_INT mumps_errno, const char* desc);
/* Export a system error to the Fortran layer (errno must be set)
   Returns mumps_errno for convenience */
MUMPS_INT mumps_io_sys_error(MUMPS_INT mumps_errno, const char* desc);
#if ! ( defined(MUMPS_WIN32) || defined(WITHOUT_PTHREAD) )
MUMPS_INT mumps_io_init_err_lock();
MUMPS_INT mumps_io_destroy_err_lock();
MUMPS_INT mumps_check_error_th();
MUMPS_INLINE MUMPS_INT mumps_io_protect_err();
MUMPS_INLINE MUMPS_INT mumps_io_unprotect_err();
#endif /* ! ( MUMPS_WIN32 || WITHOUT_PTHREAD ) */
