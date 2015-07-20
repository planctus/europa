CWT Translation
---------------

This module provides a translation file format for the TMGMT module. This file
format is custom built for the needs of the DGT translation team of the
European Commission.

This translation format is tailored to a workflow that differs from the default
TMGMT workflow. Instead of exporting each translation job in a separate file,
the DGT team expects to receive a single file containing the source translation.
A copy of this file will be made for each target language and is distributed to
the translators.

In order to accommodate for this we cannot rely on the job ID number since each
copy will have the same job ID as the source translation that was originally
exported. Instead the correct job number is determined from a combination of the
source and destination languages and the entity IDs that were exported.
