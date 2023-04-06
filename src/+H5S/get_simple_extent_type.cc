/*

Copyright (C) 2021 Pantxo Diribarne

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

Author: Pantxo Diribarne <pantxo@dibona>
Created: 2021-04-25

*/

#include <octave/oct.h>
#include <hdf5/serial/hdf5.h>

#include "../util/h5_oct_util.h"

DEFUN_DLD(get_simple_extent_type, args, nargout,
          "-*- texinfo -*-\n\
@deftypefn {} {@var{space_type} =} H5S.get_simple_extent_type (@var{space_id})\
n\
\n\
Determine the current class @var{space_type} of a dataspace @var{space_id}.\n\
\n\
@seealso{H5S.get_simple_extent_dims}\n\
@end deftypefn")
{
  octave_value_list retval;

  int nargin = args.length ();

  if (nargin != 1)
    print_usage ("H5S.get_simple_extent_type");

  // Space ID
  hid_t space_id = get_h5_id (args, 0, "SPACE_ID", "H5S.get_simple_extent_type", false);

  H5S_class_t space_type = H5Sget_simple_extent_type (space_id);

  if (space_type < 0)
    error ("H5S.get_simple_extent_type: unable to close data space object");

  return retval.append (octave_int64 (space_type));
}
