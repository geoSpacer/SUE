Hi Keith,

I copied my version to T:\commons\Keith.Olsen\matt_sue and there are common.lib files at these locations:

  "T:\Commons\Keith.Olsen\matt_sue\libs\libs\common\Debug\common.lib"
  "T:\Commons\Keith.Olsen\matt_sue\libs\libs\common\Release\common.lib"

It looks like the SUE application is linking to these statically (ie. through the .lib), so these should be what you need from this project.  It looks like the comparison operator should have been defined in:

  "T:\Commons\Keith.Olsen\matt_sue\libs\libs\common\include\Enum_With_2_Values.h"

but that didn’t seem to work.  The fix I have in there complains about it taking a performance hit, so I’m sure it’s probably not the most elegant solution.

matt

