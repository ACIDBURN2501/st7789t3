Systemd Setup
=============

To auto-start the display service at boot:

.. code-block:: bash

   sudo cp display.service /etc/systemd/system/
   sudo systemctl daemon-reexec
   sudo systemctl enable display.service
   sudo systemctl start display.service