#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "gstkmssink.h"
#include "gstvpudec.h"

#include "ximagesink.h"

GST_DEBUG_CATEGORY (gst_debug_x_image_pool);
GST_DEBUG_CATEGORY (gst_debug_x_image_sink);
GST_DEBUG_CATEGORY (CAT_PERFORMANCE);

static gboolean
plugin_init (GstPlugin * plugin)
{
  if (!gst_element_register (plugin, "vpudec", GST_RANK_PRIMARY + 1,
          GST_TYPE_VPUDEC))
    return FALSE;

  if (!gst_element_register (plugin, "kmssink", GST_RANK_SECONDARY,
          GST_TYPE_KMS_SINK))
    return FALSE;

  if (!gst_element_register (plugin, "ximagesink",
          GST_RANK_SECONDARY, GST_TYPE_X_IMAGE_SINK))
    return FALSE;

  GST_DEBUG_CATEGORY_INIT (gst_debug_x_image_sink, "ximagesink", 0,
      "ximagesink element");
  GST_DEBUG_CATEGORY_INIT (gst_debug_x_image_pool, "ximagepool", 0,
      "ximagepool object");

  GST_DEBUG_CATEGORY_GET (CAT_PERFORMANCE, "GST_PERFORMANCE");

  return TRUE;
}


GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    vpu,
    "VPU decoder",
    plugin_init, VERSION, GST_LICENSE, GST_PACKAGE_NAME, GST_PACKAGE_ORIGIN);
