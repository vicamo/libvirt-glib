/*
 * libvirt-gconfig-domain-timer-rtc.c: libvirt domain RTC timer configuration
 *
 * Copyright (C) 2012 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 * Author: Christophe Fergeau <cfergeau@redhat.com>
 */

#include <config.h>

#include "libvirt-gconfig/libvirt-gconfig.h"
#include "libvirt-gconfig/libvirt-gconfig-private.h"

#define GVIR_CONFIG_DOMAIN_TIMER_RTC_GET_PRIVATE(obj)                         \
        (G_TYPE_INSTANCE_GET_PRIVATE((obj), GVIR_CONFIG_TYPE_DOMAIN_TIMER_RTC, GVirConfigDomainTimerRtcPrivate))

struct _GVirConfigDomainTimerRtcPrivate
{
    gboolean unused;
};

G_DEFINE_TYPE(GVirConfigDomainTimerRtc, gvir_config_domain_timer_rtc, GVIR_CONFIG_TYPE_DOMAIN_TIMER);


static void gvir_config_domain_timer_rtc_class_init(GVirConfigDomainTimerRtcClass *klass)
{
    g_type_class_add_private(klass, sizeof(GVirConfigDomainTimerRtcPrivate));
}


static void gvir_config_domain_timer_rtc_init(GVirConfigDomainTimerRtc *timer)
{
    g_debug("Init GVirConfigDomainTimerRtc=%p", timer);

    timer->priv = GVIR_CONFIG_DOMAIN_TIMER_RTC_GET_PRIVATE(timer);
}


GVirConfigDomainTimerRtc *gvir_config_domain_timer_rtc_new(void)
{
    GVirConfigObject *object;

    object = gvir_config_object_new(GVIR_CONFIG_TYPE_DOMAIN_TIMER_RTC,
                                    "timer", NULL);
    gvir_config_object_set_attribute(object, "name", "rtc", NULL);
    return GVIR_CONFIG_DOMAIN_TIMER_RTC(object);
}

GVirConfigDomainTimerRtc *gvir_config_domain_timer_rtc_new_from_xml(const gchar *xml,
                                                                    GError **error)
{
    GVirConfigObject *object;

    object = gvir_config_object_new_from_xml(GVIR_CONFIG_TYPE_DOMAIN_TIMER_RTC,
                                             "timer", NULL, xml, error);
    gvir_config_object_set_attribute(object, "name", "rtc", NULL);
    return GVIR_CONFIG_DOMAIN_TIMER_RTC(object);
}
