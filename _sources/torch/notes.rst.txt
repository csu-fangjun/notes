Note
====

To clip gradient, use:

.. code-block:: bash

   tot_norm = torch.nn.utils.clip_grad_norm_(model.parameters(), max_norm=5, norm_type=2.0)
   if torch.logical_or(tot_norm.isnan(), tot_norm.isinf()):
     # skip this update
     continue
   else:
     optimizer.step()


